
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int ma=0;
    int ma2=0;
    rep(i,n){
        cin >> a[i];
        //cout << a[i] << endl;
    ma=max(a[i],ma);
    }
    int cunt=0;
    rep(i,n){
        if(a[i]!=ma){
            ma2=max(ma2,a[i]);
        }
        if(ma==a[i]){
                cunt++;
        }
    }
    if(cunt>1){
        ma2=ma;
    }
    rep(i,n){
        if(a[i]==ma){
                cout << ma2 << endl;
        }
        else{
        cout << ma << endl;
        }
    }
  //  cout << ma2 << endl;
    
}