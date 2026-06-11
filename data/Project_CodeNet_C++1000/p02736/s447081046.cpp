/*
 * @Author: RBQRBQ
 * @Date: 2020-03-21 20:39:45
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-03-22 17:33:32
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;
VI num;
int N;
bool judge(vector<int> a)
{
    for(auto p:a)
    {
        if(p==2) return false;
    }
    return true;
}
bool judge2(vector<int> a)
{
    for(auto p:a)
    {
        if(p==1) return false;
    }
    return true;
}
int main()
{
    //freopen("B.in","r",stdin);
    bool ok=true;
    read(N);
    for(int i=1;i<=N;i++)
    {
        char s;
        scanf("%c",&s);
        num.push_back((s-'0'));
    }
    VI res;
        for(int i=1;i<num.size();i++)
        {
            res.push_back(abs(num[i]-num[i-1]));
        }
    swap(res,num);
    if(num.size()==1)
    {
        cout<<num[0];
        return 0;
    }
    if(judge2(num))
    {
        ok=false;
        for(auto it=num.begin();it!=num.end();it++)
        (*it)=(*it)/2;
    }
    for(;;)
    {
        if(judge(num)||num.size()==1) break;
        VI res;
        for(int i=1;i<num.size();i++)
        {
            res.push_back(abs(num[i]-num[i-1]));
        }
        swap(res,num);

    }
    int j0=0,j1=0,o0=0,o1=0;
    N=num.size()-1;
    int q=-1;
    if(N==0)
    {
        cout<<num[0];
        return 0;
    }
    for(auto p:num)
    {
        q++;
        if(p==0)
        {

            if((N&q)==q) j0++;
            else o0++;
        }
        if(p==1)
        {
            if((N&q)==q) j1++;
            else o1++;
        }
    }
    if(j0%2==1&&j1%2==1)
    {
        if(ok) cout<<1;
        else cout<<2;
    }
    if(j0%2==0&&j1%2==1)
    {
        if(ok) cout<<1;
        else cout<<2;
    }
    if(j0%2==1&&j1%2==0)
    {
        cout<<0;
    }
    if(j0%2==0&&j1%2==0)
    {
        cout<<0;
    }
    
}