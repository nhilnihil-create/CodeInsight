#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N,a;
    cin >> N;
    a=N%10;
    if(a==3){
        cout << "bon";
    }else if(a==0||a==1||a==6||a==8){
        cout << "pon";
    }else cout << "hon";
    return 0;
}
