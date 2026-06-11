#include<iostream>
using namespace std;
bool is_possible(int a,int b,int c,int k)
{
    if(k==0)
    {
        if(b>a && c>b)
        return true;
        return false;
    }
    bool option1 = is_possible(a,b,c,k-1);
    bool option2 = is_possible(2*a,b,c,k-1);
    bool option3 = is_possible(a,2*b,c,k-1);
    bool option4 = is_possible(a,b,2*c,k-1);
    return option1 | option2 | option3 | option4;

}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int k;
    cin>>k;
    if(is_possible(a,b,c,k))
    cout<<"Yes\n";
    else 
    cout<<"No\n";
}