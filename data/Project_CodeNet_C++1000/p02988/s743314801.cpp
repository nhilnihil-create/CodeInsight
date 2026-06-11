#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],ans,anss;
    for(int i=0; i<n; i++){
       cin >> a[i];   
    }
    int count = 0;
    for(int i=1; i<n-1; i++){
       ans = max(max(a[i-1],a[i]),a[i+1]);
       anss = min(min(a[i-1],a[i]),a[i+1]);
       if(ans == a[i] || anss == a[i])
         continue;
       else
         count++;
    }
    cout << count << endl;
    return 0;
}