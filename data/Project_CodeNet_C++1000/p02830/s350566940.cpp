#include "iostream"
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    
    string result;
    for(int i=0;i<n;i++)
    {
        result=result + s[i] +t[i];
        
    }

    cout<<result<<endl;
    
    
    
    
}
