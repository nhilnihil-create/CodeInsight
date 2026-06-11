#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    vector<long long>count(200000);
    long long answer=0;
    for(int i=0; i<N; i++){
        cin>>A.at(i);
        count.at(A.at(i)-1)++;
    }
    for(int i=0; i<200000; i++){
        answer+=count.at(i)*(count.at(i)-1)/2;
    }
    for(int i=0; i<N; i++){
        if(2<count.at(A.at(i)-1)){
        cout<<answer-((count.at(A.at(i)-1))*(count.at(A.at(i)-1)-1)/2-(count.at(A.at(i)-1)-1)*(count.at(A.at(i)-1)-2)/2)<<endl;
        }
        else if(2==count.at(A.at(i)-1)){
            cout<<answer-1<<endl;
        }
        else if(count.at(A.at(i)-1==1)){
            cout<<answer<<endl;
        }
        else
        {
            cout<<answer<<endl;
        }
        
    }
}
