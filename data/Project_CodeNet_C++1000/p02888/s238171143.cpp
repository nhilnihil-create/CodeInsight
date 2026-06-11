#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)

int main(void){
    int n;
    cin >> n;
    map<int,int> mp;
    int l[n];
    rep(i,n){
        cin >> l[i];
        l[i]--;
        mp[l[i]]++;
    }
    sort(l,l+n);
    
    vector<int> num(10000,0);
    for(int i = l[0];i <= l[n-1]+l[n-2];i++){
        num[i] = num[i-1] + mp[i]; 
    }
    
    //b-a+1,a-b+1 <= c <= a+b-1
    
    ll alina = 0;
    for(int a = 0;a < n;a++){
        for(int b = a+1;b < n;b++){
            int sum = l[a]+l[b]+1;
            int sum2 = l[b]-l[a]-1;
            
            for(int c = b+1;c < n;c++){
                if(sum <= l[c])break;
                if(sum > l[c] && l[c] > sum2)alina++;
            }
        }
    }
    cout << alina << endl;
}