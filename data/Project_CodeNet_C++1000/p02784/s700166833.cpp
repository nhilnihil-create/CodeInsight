#include<bits/stdc++.h>
using namespace std;
int main(){
int h,n;
int o=0;
cin >> h >> n;
 vector<int>a(n);
 for(int i=0;i<n;i++) cin >> a[i];
 for(int i=0;i<n;i++){
   o=o+a[i];
 }
 if(o>=h) cout << "Yes";
 else if(o<h) cout << "No";
 return 0;
}