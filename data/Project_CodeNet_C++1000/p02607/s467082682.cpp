#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <strstream>
string dic_to_bin(int n)
{
    string s;
    while (n)
    {
        s+=(n%2)+'0';
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int bin_to_dic(string s)
{
    int mal=1;int dec=0;
    for(int i=s.size()-1;i>=0;--i)
    {
        dec+=(s[i]-'0')*mal;
        mal*=2;
    }
    return dec;
}
int setbit1(int num,int indx)
{
    return num|1<<indx;
}
int setbit0(int num,int indx)
{
    return num&~(1<<indx);
}
int flipbit(int num,int indx)
{
    return num^(1<<indx);
}
int getbit(int num,int indx)
{
    return (num>>indx)&1;
}
int count_ones(int num)
{
    int res=0;
    while (num)
    {
        res+=num&1;
        num>>=1;
    }
    return res;
}
void printsubset(string num)
{
    for(int i=0;i<(1<<num.size());++i)
    {
        for(int j=0;j<num.size();++j)

            if((i>>j)&1)
                cout<<num[j];
            cout<<endl;

    }
}
#include <vector>
bool prime(int num)
{
    for(int i=2;i<=num/2;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;

}
int main()
{
int n;
cin>>n;
int x,c=0;
for(int i=1;i<=n;++i)
{
    cin>>x;
    if(i%2!=0&&x%2!=0)
        c++;
}
cout<<c<<endl;
}