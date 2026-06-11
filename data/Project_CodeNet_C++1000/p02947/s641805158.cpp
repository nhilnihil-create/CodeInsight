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
using namespace std;


int main(void){
    int N;
    cin >> N;
    std::map<std::string,long> list;
    
    for(int i =0; i < N; i++){
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        list[str] += 1;
    }
    long sum = 0;

    for( auto i = list.begin(); i != list.end() ; ++i ) {
        sum += (((long)i->second - 1) * (long)i->second) / 2;
    }
    cout << sum << endl;
}