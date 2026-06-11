    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        string s, t;
        cin>>s>>t;
        int sl=s.length(), tl=t.length();
        int n=sl-tl+1;
        int x[n] = {0};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < tl; ++j)
            {
                if(s[i+j] == t[j]){
                    x[i]++;
                }
            }
        }
        int max=x[0];
        for (int i = 1; i < n; ++i)
        {
            if (x[i]>max)
            {
                max = x[i];
            }
        }
        cout<<tl-max;
    }
