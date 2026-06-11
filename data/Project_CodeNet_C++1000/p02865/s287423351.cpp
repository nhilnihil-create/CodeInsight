#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    int n;
    cin>>n;

    int cnt;
    for(int i=1;i<n/2+1;i++){
      int k=n-i;
      if(k!=i)
        cnt++;
    }

    cout<<cnt<<endl;
    
    return 0;
}  