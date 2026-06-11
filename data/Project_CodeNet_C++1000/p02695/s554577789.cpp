//BISMILLAH
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<int> a,b,c,d,A; //globaly dec kortei hobe
int ans=0;

int check()
{
    int res=0;
    for(int i=0;i<q;i++)
    {
        if(A[b[i] - 1] - A[a[i] - 1] == c[i]) {
			res += d[i];
		}
    }
    return res;
}

void makesequence(int i,int curr)
{
    if(i>=n) // n lengh er e hote hobe A list k . 111 jokhn hobe tokhn tekei eikhane ese , sum hobe . 11,12,1,22,3 esob sequence lagbe na.
    {
        ans=max(ans,check());
        return;

    }
    for(int j=curr;j<=m;j++) //A sequence tar max value hote pare m
    {
        A.push_back(j);
        makesequence(i+1,j);
        A.pop_back(); // 111 jokhn hobe then recursion sesh hole last er 1 pop hoye j++ hobe then 112 hobe .tai pop
    }
}
int main()
{
    cin>>n>>m>>q;
    a=b=c=d=vector<int>(q); //sob gular size q

    for(int i=0;i<q;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]; // ai,bi,ci,di nilam q times
    }

    makesequence(0,1);

    cout<<ans<<endl;
}
