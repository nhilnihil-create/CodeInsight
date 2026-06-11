#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int  n;
    cin >> n ;
    VI l(n);
    rep(i,n)cin >> l[i];
    sort(l.begin(),l.end());
    int cnt=0;
    rep(i,n-2){
        for(int j=i+1;j<n-1;j++){
           for(int k=j+1;k<n;k++){
               if(l.at(i)+l.at(j)>l.at(k))cnt++;
               else break;
               
           } 
        }
    }
    
    cout << cnt << endl;
   
}
