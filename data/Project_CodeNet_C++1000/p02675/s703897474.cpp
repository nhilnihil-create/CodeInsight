#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
void input()
{
    cin>>N;
}

void solve()
{
    if(N%10==3) cout<<"bon"<<endl;
    else if(N%10==0 || N%10==1 || N%10==6 || N%10==8) cout<<"pon"<<endl;
    else cout<<"hon"<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}