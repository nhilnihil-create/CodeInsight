#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() 
{
    int N;
    cin>>N;

    vector<int>A,Gusu;
    for(int i=0;i<N;++i)
    {
        int a;
        cin >>a;
        A.push_back(a);
    }

    while (!A.empty())
    {
        if(A.back()%2==0)
        {
            Gusu.push_back(A.back());
        }
        A.pop_back();
    }
    
    string kyoka;
    bool is = all_of(Gusu.begin(),Gusu.end(),[](int i){return i%3==0 || i%5==0;});
    is ? kyoka="APPROVED":kyoka="DENIED";
    cout<<kyoka<<endl;
}