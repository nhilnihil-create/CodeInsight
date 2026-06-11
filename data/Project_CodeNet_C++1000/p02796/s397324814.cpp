#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(void){
    int n;
    cin >> n;
    int x[n],l[n];
    for(int i = 0;i < n;i++)cin >> x[i] >> l[i];
    
    P p[n];
    for(int i = 0;i < n;i++){
        p[i].first = x[i]+l[i];
        p[i].second = x[i]-l[i];
    }
    
    sort(p,p+n);
    ll alina = 0,gray = -1e18;
    for(int i = 0;i < n;i++){
        //cout << p[i].first << endl;
        if(gray <= p[i].second){
            //cout << i << endl;
            alina++;
            gray = p[i].first;
        }
    }
    cout << alina << endl;
}