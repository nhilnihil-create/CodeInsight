#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
    int N;
    cin >> N;

    //map<string, int> msc;
    map<string,int> sums;
    int total = 0;
    for (int i = 0; i < N; i++) {
        string name;
        int time;
        cin >> name >> time;
        //msc[name] = time;
        total += time;
        sums[name] = total;
    }

    string X;
    cin >> X;
    cout << total - sums[X] << endl;
}