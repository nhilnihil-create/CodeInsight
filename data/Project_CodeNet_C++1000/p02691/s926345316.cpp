#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool operator<(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first){
        a.second < b.second;
    } else {
        a.first < b.first;
    }
}

int main(){
    int n;
    vector<pair<int,int>> viiValue(n);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int Ai;
        scanf("%d", &Ai);
        viiValue.push_back(make_pair(i + 1 - Ai,0));
        viiValue.push_back(make_pair(i + 1 + Ai,1));
    }    
    sort(viiValue.begin(),viiValue.end());
  
    long int nCount = 0;
    int i = 0;
    while(i < viiValue.size()){
        if(viiValue[i].second == 1){
            i++;
            continue;
        }
        int a = viiValue[i].first;
        long int nCount0 = 0;
        long int nCount1 = 0;
        while(viiValue[i].first == a && viiValue[i].second == 0){
            i++;
            nCount0++;
        }
        while(viiValue[i].first == a && viiValue[i].second == 1){
            i++;
            nCount1++;
        }
        nCount += nCount0 * nCount1;
    }
    printf("%ld", nCount);
    return 0;
}
