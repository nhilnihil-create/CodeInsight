#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);
       cin.tie(0);
   
    int n, cnt= 0;
    cin >> n;
    int a[n];
    for(int i =0 ;i<n; i++){ 
    	cin >> a[i];
 }
    sort(a,a+n);
 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                cnt += a[i]+a[j] > a[k];
            }
        }
    }
                    
    cout << cnt << endl;  
    }  