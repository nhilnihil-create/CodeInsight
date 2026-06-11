#include <bits/stdc++.h>
using namespace std;

        int main() {
            
            long long int a,b,c,k;
            cin >> a >>b >>c>>k;
            
        if(a==k)
            cout<< a;
        
        else if(a>k)
            cout<< k;
        
        else{
            
            if(a+b==k)
               cout<< a;
            
            else if(a+b+c>=k){
                int ans =0;
                for(int i=0; i<k-a-b; i++){
                ans+=-1;
                }
            cout << a+ans;

            }
      }
            return 0;
}