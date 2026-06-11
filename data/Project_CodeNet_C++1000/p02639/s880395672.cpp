
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arra[6];
    cin>>arra[0]>>arra[1]>>arra[2]>>arra[3]>>arra[4];
    for(int i=0;i<=5;i++) {
        if(arra[i]==0) {
            cout<<i+1<<endl;
            break;
        }
    }

}
