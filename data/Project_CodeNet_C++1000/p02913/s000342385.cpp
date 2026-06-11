#include<bits/stdc++.h>
using namespace std;

const unsigned long long bigp=(1ULL<<61)-1ULL;
const unsigned long long smallp=(1ULL<<31)-1ULL;
const unsigned long long smallpplus=(1ULL<<31);
const unsigned long long smallpminus=(1ULL<<30)-1ULL;

unsigned long long b=40787;

class hash_mod{
    public:
    unsigned long long val;
    unsigned long long val_u, val_d;
    unsigned long long another_u, another_d;
    unsigned long long m, m_u, m_d;

    void remainder(){
        val_u=(val>>61);
        val_d=val&bigp;
        if(val_u + val_d <bigp) val= val_u + val_d;
        else val= (val_u + val_d) -bigp;
    }

    void update(unsigned long long v){
        val=v;
        remainder();
    }

    void addition(unsigned long long another){
        val+=another;
        remainder();
    }

    void subtraction(unsigned long long another){
        val+=bigp;
        val-=another;
        remainder();
    }

    void multiple(unsigned long long another){
        val_u=(val>>31);
        val_d=val&smallp;
        another_u=(another>>31);
        another_d=another&smallp;
        m=val_u*another_d + val_d*another_u;
        m_u=(m>>30);
        m_d=m&smallpminus;
        val=0;
        val+=val_u*another_u*(2ULL);
        val+=m_u + m_d*smallpplus;
        val+=val_d*another_d;
        remainder();
    }
};

int main(){
    //input
    unsigned long long N;
    string S;
    cin >> N >> S;

    //calc
    unsigned long long i,j;
    hash_mod S_hash;
    char c='a';
    c--;
    hash_mod sub, b_pow[N/2];
    b_pow[0].update(1ULL);
    for(i=1; i<N/2; i++){
        b_pow[i].update(b);
        b_pow[i].multiple(b_pow[i-1].val);
    }

    for(i=N/2; i>=1; i--){
        set<pair<unsigned long long, unsigned long long> > st;
        set<pair<unsigned long long, unsigned long long> >::iterator it, itne;
        S_hash.update(0ULL);
        for(j=0; j<i; j++){
            S_hash.multiple(b);
            S_hash.addition((unsigned long long)(S[j]-c));
        }
        st.insert(make_pair(S_hash.val,0ULL));
        for(j=i; j<N; j++){
            sub.update((unsigned long long)(S[j-i]-c));
            sub.multiple(b_pow[i-1].val);
            S_hash.subtraction(sub.val);
            S_hash.multiple(b);
            S_hash.addition((unsigned long long)(S[j]-c));
            st.insert(make_pair(S_hash.val,j-(i-1)));
        }
        for(it=st.begin(); it!=st.end(); it++){
            itne=st.lower_bound(make_pair((*it).first+1ULL,0ULL));
            itne--;
            if((*it).second+i<=(*itne).second) break;
        }
        if(it!=st.end()) break;
    }

    //output
    cout << i << endl;
    system("pause");
    return 0;
}