#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;
struct XX{
int s;
    int e;
};

class xxGreater {
public:
bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
if((riLeft.s) == (riRight.s)){
return riLeft.e < riRight.e;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
           //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.s) > (riRight.s);
    }
};


int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long a,b,c,d;
    cin >> a>> b>>c>>d;
long long ans=a*c;
ans=max(ans,a*d);
ans=max(ans,b*c);
ans=max(ans,b*d);


cout << ans <<endl;

}


//cout << "Hello World" << endl;
