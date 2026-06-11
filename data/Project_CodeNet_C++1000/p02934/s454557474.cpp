/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int n;
    cin>>n;
    double sum=0.0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum += (double)1/x;
    }
    sum = 1/sum;
    cout<<fixed<<setprecision(7)<<sum<<endl;
    return 0;
}

