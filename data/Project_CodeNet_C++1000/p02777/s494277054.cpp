#include<bits/stdc++.h>
using namespace std;
int main(){



    int n, m;
    string a, b, c;
    cin>>a>>b>>n>>m>>c;

    if(a==c)
        n--;
    else if(b==c)
        m--;

    cout<<n<<" "<<m;


return 0;


}
