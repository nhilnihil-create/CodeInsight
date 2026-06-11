#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X,Y,Z;
    cin>>X>>Y>>Z;
    if(X>=1&&Y>=1&&Z>=1&&X<=100&&Y<=100&&Z<=100){
        cout<<Z<<" "<<X<<" "<<Y;
    }
    return 0;
}