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
    int k,x;
    cin>>k>>x;
    for(int i=-(k-1);i<=(k-1);i++){
        cout<<x+i<<" ";
    }
    cout<<"\n";
    return 0;
}

