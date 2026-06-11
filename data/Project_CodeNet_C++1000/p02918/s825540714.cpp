#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef string::size_type sz;
struct loca
{
    sz be,ed,len;
};
typedef vector<loca>::size_type vsz;
int couterhappy(const string& a)
{
    if(a.size()==0||a.size()==1)
    {
        return 0;
    }
    int sum=0;
    for(sz i=1;i!=a.size()-1;i++)
    {
        if((a[i]=='L'&&a[i-1]==a[i])||(a[i]=='R'&&a[i+1]==a[i]))
        {
            sum++;
        }
    }
    if(a[0]=='R'&&a[1]=='R')
    {
        sum++;
    }
    if(a[a.size()-1]=='L'&&a[a.size()-2]=='L')
    {
        sum++;
    }
    return sum;
}
void myrever(string& s,const loca& a,char c)
{
    for(sz i=a.be;i<=a.ed;i++)
    {
        s[i]=c;
    }
}
bool mycomp(const loca& left,const loca& right)
{
    return (left.len>right.len)?true:false;
}
bool mycomp2(const loca& left,const loca& right)
{
    return (left.len<right.len)?true:false;
}
int main(int argc, const char** argv) 
{
    int n,changetime;
    string target,Lt,Rt,Lt2,Rt2,Lt3,Rt3;
    cin>>n>>changetime;
    cin>>target;
    Lt=target,Rt=target,Lt2=target,Rt2=target,Lt3=target,Rt3=target;
    vector<loca> Linter,Rinter,Linter2,Rinter2,Linter3,Rinter3;
    loca temp;
    sz i=0,j=i;
    while (j!=n&&i!=n)
    {
        j=i;
        temp.be=i;
        while(target[i]==target[j]&&j!=n)
        {
            j++;
        }
        temp.ed=j-1;
        temp.len=temp.ed-temp.be;
        if(target[i]=='L')
        {
            Linter.push_back(temp);
        }
        else
        {
            Rinter.push_back(temp);
        }
        i=j;
    }
    if(Linter.size()<=changetime||Rinter.size()<=changetime)
    {
        cout<<(n-1);
        return 0;
    }
    Linter2=Linter,Rinter2=Rinter,Linter3=Linter,Rinter3=Rinter;
    sort(Linter.begin(),Linter.end(),mycomp);
    sort(Rinter.begin(),Rinter.end(),mycomp);
    sort(Linter2.begin(),Linter2.end(),mycomp2);
    sort(Rinter2.begin(),Rinter2.end(),mycomp2);
    for(vsz i=0;i!=changetime;i++)
    {
        myrever(Lt,Rinter[i],'L');
        myrever(Rt,Linter[i],'R');
        myrever(Lt2,Rinter2[i],'L');
        myrever(Rt2,Linter2[i],'R');
        myrever(Lt3,Rinter3[i],'L');
        myrever(Rt3,Linter3[i],'R');
    }
    int sum[6]={couterhappy(Lt),couterhappy(Rt),couterhappy(Lt2),couterhappy(Rt2),couterhappy(Lt3),couterhappy(Rt3)};
    sort(sum,sum+6);
    cout<<sum[5];
    return 0;
}
