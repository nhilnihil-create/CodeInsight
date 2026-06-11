#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    int x,n,ans=-1;
    cin >> x >> n;
    int aa;
    //int min1 = 101,min2=101;
    vector<bool> a(102,true);
    rep(i,n){
        cin >> aa;
        a[aa]=false;
    }
    //sort(a.begin(),a.end());
    for(int i=0;i<=101;i++){
        if(a[i]){
            if(abs(x-i)<abs(x-ans)){
                ans=i;
            }
            /*
            for(int i=0;i<=100;i++){
                if(x-i==min1 and min1!=0 and min1>0){
                    min1=x-i;
                }
                if(i-x==min2 and min2!=0 and min2>0){
                    min2=i-x;
                }
                if(min1==min2) ans=min1;
                else if(min1>min2)ans=min2;
                else ans=min1;

            }*/
        }//else ans=x;
    }
    cout << ans << endl;
    /*
    rep(i,100){
        rep(j,n){
            if(min > x-i and x-i >0){
                min=x-i;
                if(min==a[i]){
                    ans=temp;}
                    ans=i;
                temp=ans;
                
            }
        }
    }
    cout << ans << endl;*/
}