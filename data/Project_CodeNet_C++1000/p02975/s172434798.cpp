#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

void swap(ll& a, ll& b){
    ll t;
    t = a;
    a = b;
    b = t;
}
int main() {
    

    ll n;
    cin >> n;
    unordered_map<ll, ll> abcList;
    for (ll i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        abcList[tmp]++;
    }
    if(abcList.size() > 3){
        cout << "No" << endl;
        return 0;
    }else if(abcList.size() == 3){
        bool flag = true;
        auto itr = abcList.begin();
        ll num1 = itr -> second;
        while(itr != abcList.end()){
            if(num1 != itr -> second){
                flag = false;
                break;
            }
            itr++;
        }
        if(!flag){
            cout << "No" << endl;
            return 0;
        }else{
            itr = abcList.begin();
            unsigned long long number1 = itr -> first;
            itr++;
            unsigned long long number2 = itr -> first;
            itr++;
            unsigned long long number3 = itr -> first;
            if(number1 == (number2 ^ number3)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }else if(abcList.size() == 2){
        ll num1 = 0;
        ll number1 = 0;
        ll num2 = 0;
        ll number2 = 0;
        auto itr = abcList.begin();
        num1 = itr -> second;
        number1 = itr -> first;
        itr++;
        num2 = itr -> second;
        number2 = itr -> first;
        if(num2 < num1){
            swap(num1, num2);
            swap(number1, number2);
        }
        if(number1 != 0){
            cout << "No" << endl;
            return 0;
        }else{
            if(num1*2 == num2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }else if(abcList.size() == 1){
        auto itr = abcList.begin();
        if(itr -> first == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }



}