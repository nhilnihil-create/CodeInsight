#include<iostream>
#include<string>
using namespace std;
int main()
{
    long long i,j,total=0;
    string s;
    cin>>s;
    i=0;
    j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            total++;
        }
        i++;
        j--;
    }
    cout<<total<<endl;
    return 0;
}