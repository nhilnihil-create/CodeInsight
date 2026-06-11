#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int main()
{
    long long n,i,max=0,k=1,j;
    string s,c[200005];
    map<string,long long>m;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        m[s]++;
        if(m[s]>max)
        {
            k=1;
            c[k]=s;    
            k++;   
            max=m[s];   
        }
        else if(m[s]==max)
        {
            c[k]=s;
            k++;
        }
    }
    sort(c+1,c+k);
    for(j=1;j<k;j++)
    {
        cout<<c[j]<<endl;
    }
    return 0;
}