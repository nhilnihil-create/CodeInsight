#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
// User defined sizeof macro
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


int main()

{
    optimize();
    int a,b;
    cin>>a>>b;

    string s1=to_string(a);
    string cpa;
    string s2=to_string(b);
    string cpb;
    for(int i=0;i<b ;i++) cpa+=s1;
//    cout<<cpa;
//    cout<<endl;
    for(int i=0;i<a ;i++) cpb+=s2;
//    cout<<cpb;
//     cout<<endl;
     if(cpa>cpb)
        cout<<cpb;
     else cout<<cpa;















    return 0;
}



