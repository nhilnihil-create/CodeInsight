//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

// 順列全探索
// N!
// next_permutation
int main (){
    // 入力
    int n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        a[i] = i;
    }

    double sum = 0; // 最後にn!で割ると答え
    double x_sa, y_sa;
    // 順列全探索
    do{
        double dist = 0;
        for(int i=0;i<n-1;i++){
            x_sa = x[a[i+1]]-x[a[i]];
            y_sa = y[a[i+1]]-y[a[i]];
            dist += sqrt(x_sa*x_sa + y_sa*y_sa);
        }
        sum += dist;
    }while(next_permutation(a.begin(),a.end()));

    // nの階上
    double kai = 1;
    for(double i=1;i<=n;i++){
        kai*=i;
    }
    
    printf("%.8f",sum/kai);
}