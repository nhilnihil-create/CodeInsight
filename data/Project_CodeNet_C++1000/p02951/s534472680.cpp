#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll ma1,cup1,cup2;
    cin>>ma1>>cup1>>cup2;
    ll aki=ma1-cup1;
    ll idou=min(aki,cup2);
    cout<<cup2-idou<<endl;
}
