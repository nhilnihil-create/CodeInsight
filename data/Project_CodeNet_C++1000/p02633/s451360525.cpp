#include <bits/stdc++.h>
using namespace std;


int main()  {
    int x,angle,steps=1;
    cin>>x;
    angle=x;
    while(x%360!=0) {
        x+=angle;
        steps++;
    }
    cout<<steps;
    return 0;
}
