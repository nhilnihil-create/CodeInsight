#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return b<a;
}
int main(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> pos, neg;
    for (int i=0; i<n; i++){
        int x; cin>>x;
        if (x>=0)pos.push_back(x);
        else neg.push_back(x);
        sum += abs(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), compare);
    if (pos.size() == 0){
        cout<<sum+2*neg[0]<<endl;
        cout<<neg[0]<<" "<<neg[neg.size()-1]<<endl;
        int temp = neg[0] - neg[neg.size()-1];
        for (int i=1; i<neg.size()-1; i++){
            cout<<temp<<" "<<neg[i]<<endl;
            temp -= neg[i];
        }
    }
    else if (neg.size() == 0){
        if (pos.size() == 2){
            cout<<pos[1]-pos[0]<<endl;
            cout<<pos[1]<<" "<<pos[0]<<endl;
            return 0;
        }
        cout<<sum-2*pos[0]<<endl;
        cout<<pos[0]<<" "<<pos[pos.size()-1]<<endl;
        int temp = pos[0] - pos[pos.size()-1];
        for (int i=1; i<pos.size()-2; i++){
            cout<<temp<<" "<<pos[i]<<endl;
            temp -= pos[i];
        }
        cout<<pos[pos.size()-2]<<" "<<temp<<endl;
    }
    else{
        cout<<sum<<endl;
        int temp = neg[0];
        for (int i=0; i<pos.size()-1; i++){
            cout<<temp<<" "<<pos[i]<<endl;
            temp -= pos[i];
        }
        cout<<pos[pos.size()-1]<<" "<<temp<<endl;
        temp = pos[pos.size()-1] - temp;
        
        for (int i=1; i<neg.size(); i++){
            cout<<temp<<" "<<neg[i]<<endl;
            temp -= neg[i];
        }
    }

}