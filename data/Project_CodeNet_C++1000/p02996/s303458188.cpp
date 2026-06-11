#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool compair(pair<long long, long long> a, pair<long long, long long> b){
    return a.second < b.second;
}

int main(){
    long long n;
    cin >> n;

    vector<pair<long long, long long> > v;

    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compair);

    long long time = 0;

    bool flag = true;

    for(long long i = 0; i < v.size(); i++){
        time += v[i].first;
        if(time > v[i].second){
            flag = false;
            break;
        }
    }

    if(flag == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}