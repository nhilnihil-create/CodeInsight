#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<long long int, int> mp;
    long long int tmp=0;
    vector<long long int> vec;
    for(int n=0; n<N; n++) {
        long long int A;
        cin >> A;
        mp[A]++;
        tmp ^= A;
        if(mp[A]==1) {
            vec.push_back(A);
        }
    }
    if(tmp) {
        cout << "No" << endl;
    } else {
        if(mp.size()>3) {
            cout << "No" << endl;
        } else {
            bool flag=true;
            if(mp[0]==0) {
                int cnt1=mp[vec[0]];
                long long int num1=vec[0];
                int cnt2=mp[vec[1]];
                long long int num2=vec[1];
                int cnt3=mp[vec[2]];
                long long int num3=vec[2];
                if(cnt1==cnt2 && cnt2==cnt3) {
                    if((num1^num2)==num3) {
                        cout << "Yes" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                } else {
                    cout << "No" << endl;
                }
            } else {
                if(mp.size()==3) {
                    cout << "No" << endl;
                } else {
                    int cnt1=mp[vec[0]];
                    long long int num1=vec[0];
                    if(mp.size()==1) {
                        cout << "Yes" << endl;
                    } else {
                        int cnt2=mp[vec[1]];
                        long long int num2=vec[1];
                        if(num1==0) {
                            if(cnt1*2==cnt2) {
                                cout << "Yes" << endl;
                            } else {
                                cout << "No" << endl;
                            }
                        } else {
                            if(cnt2*2==cnt1) {
                                cout << "Yes" << endl;
                            } else {
                                cout << "No" << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
    
}