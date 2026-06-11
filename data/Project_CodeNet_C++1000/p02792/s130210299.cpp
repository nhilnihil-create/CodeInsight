#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vector<vi> kani(9,vi(9,0));
    for(int i=1;i<=n;i++){
        int top,end;
        end=i%10;
        if(end==0) continue;
        int temp=i;
        while(temp>0){
            top=temp%10;
            temp/=10;
        }
        kani[top-1][end-1]++;
    }
    ll ans=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ans+=kani[i][j]*kani[j][i];
        }
    }
    cout << ans << endl;
}