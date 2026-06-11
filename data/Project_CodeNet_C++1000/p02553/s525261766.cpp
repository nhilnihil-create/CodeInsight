#include<bits/stdc++.h>
#define ssg set<long long int , greater<long long int>>
using namespace std;

int main()
{
    long long int a, b, c, d, e, f, max1, max2, max3, max4;
    cin>>a>>b>>c>>d;
    e=a;
    f=c;
    max1=e*f;
    e=b;
    f=c;
    max2=e*f;
    e=a;
    f=d;
    max3=e*f;
    e=b;
    f=d;
    max4=e*f;
    ssg set1;
    set1.insert(max1);
    set1.insert(max2);
    set1.insert(max3);
    set1.insert(max4);
    set<int > :: iterator it;
    cout<<*set1.begin()<<endl;
    return 0;
}
