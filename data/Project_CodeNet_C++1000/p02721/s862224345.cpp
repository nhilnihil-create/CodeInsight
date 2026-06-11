#include<bits/stdc++.h>
using namespace std;
int ar[ 200009 ],br[ 200009 ];
int main()
{
    int n,k,i,j,c,c1,c2;
    string s;
    cin>>n>>k>>c;
    c1=c2=c;
    getchar();
    cin>>s;
    for(i = 0,j=n-1 ;i<n ;i++,j-- )
    {
        if(s[i]=='o' && c1>=c)
        {
            ar[i+1]=ar[i]+1;
            c1=0;
        }
        else{
            c1++;
            ar[i+1]=ar[i];
        }

        if(s[j]=='o' && c2>=c)
        {
            br[i+1]=br[i]+1;
            c2=0;
        }
        else{
            c2++;
            br[i+1]=br[i];
        }
    }
    for(i = 1 ;i<=n;i++)
    {
        //cout<<ar[i-1]<<"  "<<br[n-i]<<endl;
        if(ar[i-1]+br[n-i]<k && s[i-1]=='o')
            cout<<i<<endl;
    }

}
