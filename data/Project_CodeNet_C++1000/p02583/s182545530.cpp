#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n = 0;
    cin >> n;
    int l[n];
    for(int i = 0;i<n;i++) cin >> l[i];
  	sort(l,l+n);
    int ans = 0;
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<i;j++){
        	for(int k = 0;k<j;k++){
            	if(l[i] != l[j] && l[i] != l[k] && l[k] != l[j] && l[j] +l[k] >l[i]){
                  ans++;
                }
            }
        }  
    }
    cout<<ans;
    return 0;
}