#include        <bits/stdc++.h>
using namespace std;

int     main() {
        int N;
        cin >>N;
        vector<int> AP(0);
        vector<int> AM(0);
        vector<int> AZ(0);
        for (int i=0; i<N; i++) {
                int A;
                cin >>A;
                if (0<A)
                        AP.push_back(A);
                else if (0>A)
                        AM.push_back(A);
                else
                        AZ.push_back(0);
        }
        int IP=0;
        int IM=0;
        if (0!=AZ.size()) {
                for (int i=0; i<AZ.size(); i++)
                        if (AP.size()>AM.size())
                                AM.push_back(0);
                        else
                                AP.push_back(0);
        }
        if (AP.size())
                sort(AP.begin(), AP.end());
        if (AM.size()) {
                sort(AM.begin(), AM.end());
                reverse(AM.begin(), AM.end());
        }
        vector<vector<int>> B;
        if (N>1) {
                for (int i=0; i<N-1; i++) {
                        if (IP==AP.size()) {
                                //only minus
                                AP.push_back(AM.at(IM)-AM.at(IM+1));
                                B.push_back({AM.at(IM), AM.at(IM+1)});
                                IM++;
                                IM++;
                        } else if (IM==AM.size()) {
                                //only plus
                                AM.push_back(AP.at(IP)-AP.at(IP+1));
                                B.push_back({AP.at(IP), AP.at(IP+1)});
                                IP++;
                                IP++;
                        } else {
                                //both available
                                if (AP.size()-IP>AM.size()-IM) {
                                        AM.push_back(AM.at(IM)-AP.at(IP));
                                        B.push_back({AM.at(IM), AP.at(IP)});
                                } else {
                                        AP.push_back(AP.at(IP)-AM.at(IM));
                                        B.push_back({AP.at(IP),AM.at(IM)});
                                }
                                IP++;
                                IM++;
                        }
                }
        }
        if (IP==AP.size())
                cout <<AM.at(IM) <<endl;
        else
                cout <<AP.at(IP) <<endl;
        for (int i=0; i<B.size(); i++)
                cout <<B.at(i).at(0) <<' ' <<B.at(i).at(1) <<endl;
        return 0;
};