#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <math.h>
using namespace std;

int main(void){
    long H,N;
    cin >> H >> N;
    long sum = 0;
    for(int i =0; i < N; i++){
        long tmp = 0;
        cin >> tmp;
        sum += tmp;
    }
    if(sum >= H){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}