#include<bits/stdc++.h>
using namespace std;
string str;
int N;
void connect(int a,int b)   //ou-ou
{
    cout<<a<<" "<<b<<endl;
    cout<<a<<" "<<a+1<<endl;
    cout<<a+1+N<<" "<<b+1<<endl;
    cout<<a+N<<" "<<a+1+N<<endl;
}
int main()
{
    cin>>N;
    int dN=N;
    ios::sync_with_stdio(false);
    while(dN)
    {
        if(dN&1) str="1"+str;
        else str="0"+str;
        dN>>=1;
    }
    int p=0;
    for(int i=1;i<str.size();++i)
        if(str[i]=='1')
            p=i;
    if(N<=2||p==0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<2<<" "<<3<<endl;
    cout<<3<<" "<<1+N<<endl;
    cout<<1+N<<" "<<2+N<<endl;
    cout<<2+N<<" "<<3+N<<endl;
    int j=1;
    for(int i=4;i<N;i+=2)
    {
        connect(i,1<<j);
        for(int k=0;k<str.size();++k)
        {
            if((1<<k)==i&&str[str.size()-1-k]=='1')
            {
                j=k;
                break;
            }
        }
    }
    if(N%2==0)
    {
        cout<<N<<" "<<(1<<(str.size()-1-p))<<endl;
        cout<<N+N<<" "<<(1<<str.size()-1)<<endl;
    }
    return 0;
}