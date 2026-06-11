#include <bits/stdc++.h>

using namespace std;

int A,B,C,PAV;

int main() {
    cin>>A>>B>>C;
    PAV=A-B;
    {if(PAV>C)
     cout<<0<<endl;
     else if(PAV<C)
     cout<<C-PAV<<endl;
     else
     cout<<0<<endl;
    }
}