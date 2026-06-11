#include <iostream>

using namespace std;

int main() {
    int N, L;
    cin>>N>>L;

    int R=L+N-1;
    int eat;

    if(R<=0)eat=R;
else if(L>=0)eat=L;
 else eat=0;

 int answer=(R+L)*(R-L+1)/2-eat;

 cout<<answer<<endl;
}

