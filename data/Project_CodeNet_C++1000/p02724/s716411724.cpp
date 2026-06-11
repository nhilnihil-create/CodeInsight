#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int count500=0,count5=0;
    while(x>=500){
        x-=500;
        count500++;
    }
    while(x>=5){
        x-=5;
        count5++;
    }
    cout << count500*1000+count5*5 << endl;
}