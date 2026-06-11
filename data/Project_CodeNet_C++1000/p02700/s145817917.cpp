#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int a,b,c,d;

bool f()
{
    while(true){
        c-=b;
        if(c<=0)return true;
        a-=d;
        if(a<=0)return false;
    }
}

int main()
{
    cin>>a>>b>>c>>d;
    cout<<(f()?"Yes":"No");
}
