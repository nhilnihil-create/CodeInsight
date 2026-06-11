#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int t;
    cin>>t;
    vector<int >v,v1;
    for(int i=0;i<t;i++){
        int x;
        cin>>x;
        v.push_back(x);
        int y;
        cin>>y;
        v1.push_back(y);
    }
    int k=0,c=0;
    for(int i=0;i<t;i++)
    {
        if(v[i]==v1[i]&&(v[i+1]||v1[i+1]!=v[i]))

            c++;
             else
            c=0;
        if(c==3){
            k=1;
        break;
        }
        //cout<<c<<endl;
     //   cout<<v[i]<<" "<<v1[i]<<endl;
    }
    if(k==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
