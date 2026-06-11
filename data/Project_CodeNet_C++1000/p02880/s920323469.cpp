#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,c=0,i;
    cin>>n;
    for(i=1;i<10;i++){
        if(n%i==0&&n/i<10)
            c++;
    }
    if(c>0){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}
