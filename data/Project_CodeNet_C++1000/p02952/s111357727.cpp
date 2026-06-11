#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,p,h[1000010],m=0,max=0;
    int n;
    string s;
    cin >> n;
    s=to_string(n);
    for(i=1;i<=n;i++)
    {
        if(to_string(i).size()%2!=0)
        {
            m++;
        }
    }
    cout << m << endl;
    return 0;

}
