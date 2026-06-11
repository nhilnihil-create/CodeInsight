#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
 vector<pair<int,int>>task;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int A,B;
        cin>>A>>B;
        task.emplace_back(B,A);
    }
    sort(task.begin(),task.end());
     for(int i=0;i<N;i++){
    }
    int sum=0;
    string ans="Yes";
    for(auto a:task){
        sum+=a.second;
        if(sum>a.first){
            ans="No";
        }
    }
    cout<<ans<<endl;
}