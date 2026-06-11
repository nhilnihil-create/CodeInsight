#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string str;
    int n;
    cin>>n;
    cin>>str;
    int i=0,j=str.length()-1,ans=0;
    while(i<j){
        if(str[i]=='R' && str[j]=='W'){
            i++;
            j--;
        }
        else if(str[i]=='R' && str[j]!='W')
           i++;
        else if(str[i]!='R' && str[j]=='W')
          j--;
        else{
            swap(str[i],str[j]);
            i++;
            j--;
            ans++;
        }
        
    }
    cout<<ans<<endl;
   
}
