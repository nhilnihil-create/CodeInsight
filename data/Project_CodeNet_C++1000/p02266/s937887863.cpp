#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    string sh;
    int tmp=0;
    getline(cin,sh);
    vector <int> a,b;
    a.push_back(0);
    for (char i : sh) {
        if(i =='_') a.push_back(tmp);
        else if(i =='/') a.push_back(++tmp);
        else a.push_back(--tmp);
    }
    auto it=a.begin();
    while(it!=a.end())
    {   int area=0,judge=1;
        auto result=find(it+1,a.end(),*it);
          if(result!=a.end()) {
            for (auto i = it+1; i != result; i++) {
                judge *= (*i<=*it);
                area += (*it-*i);
            }
            if(judge>0&&area>0) {b.push_back(area);it=result;}
            else it++;
        }
        else it++;
    }
    if(b.begin()!=b.end()) {
        cout << accumulate(b.begin(), b.end(), 0) << endl;
        cout <<b.end()-b.begin();
        for (auto i = b.begin(); i != b.end(); i++) {
            cout << " "<< *i;
        }
        cout << endl;
    }
    else cout<<0<<endl<<0<<endl;
    return 0;
}

