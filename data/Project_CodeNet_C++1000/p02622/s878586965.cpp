#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    long long sum=0;
    cin>>a>>b;
    for(int i=0 ; i<a.size(); i++){
        if(a[i]!=b[i]){
            sum++;
        }
    }

      
        cout<<sum;
      

}
