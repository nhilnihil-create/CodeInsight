#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef struct _dot{
    int x;
    int y;
}Dot;

double My_Distance(Dot a,Dot b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int P(int N){
    
    int ans = 1;
    for(int i=1;i<=N;i++) ans *= i;
    return ans;
}

int main(){
    
    int N; cin >> N;
    double sum = 0;
    Dot data[N];
    vector<int> one_case;
    for(int i=0;i<N;i++){ cin >> data[i].x; cin >> data[i].y; }
    for (int i=0;i<N;i++) { one_case.emplace_back(i); }
 
    do {
        int size = one_case.size();
        for(int i=0;i<size-1;i++){
            sum += My_Distance(data[one_case[i]],data[one_case[i+1]]);
        }
    } while (next_permutation(one_case.begin(), one_case.end()));
    
    printf("%.10f\n",sum/P(N));
}