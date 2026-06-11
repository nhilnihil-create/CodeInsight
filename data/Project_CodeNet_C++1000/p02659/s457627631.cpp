#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j=0,n,a=0,x,z,c,ans=0,m1,p=1;
    string b,b2;
    cin >> a >> b2;
    if(a==1 && b2=="0.01")
    {
        cout << "0" << endl;
        return 0;
    }
    b2=b2.erase(1,1);
    p=stoi(b2);
    n=a*p;
    b=to_string(n);
    p=b.size();
    if(p>2)
    {
        b=b.erase(p-2);
    }
    cout << b << endl;   
    return 0;
}