#include <iostream>
#include <algorithm>

std::vector<unsigned> gaps;

unsigned insertion_sort(unsigned a[], unsigned n, unsigned gap = 1){
  unsigned count = 0;
  for(unsigned i = gap; i < n; i++){
    unsigned v = a[i];
    int j = i - gap;
    while(j >= 0 && a[j] > v){
      a[j+gap] = a[j];
      j -= gap;
      count++;
    }
    a[j+gap] = v;
  }
  return count;
}

void make_gap_table(unsigned n){
  unsigned h = 1;
  unsigned i = 1;
  while(h <= n){
    gaps.push_back(h);
    h = pow(4,i) + 3*pow(2,i-1) + 1;
    i++;
  }
  std::reverse(gaps.begin(),gaps.end());
}

void shell_sort(unsigned a[], unsigned n){
  make_gap_table(n);
  unsigned count = 0;
  for(auto const &v : gaps){
    count += insertion_sort(a,n,v);
  }

  std::cout << gaps.size() << '\n';

  for(int i=0;i<gaps.size()-1;i++){
    std::cout << gaps[i] << ' ';
  }
  std::cout << gaps[gaps.size()-1] << '\n';

  std::cout << count << '\n';
}

int main(){
  unsigned n;
  unsigned buf;
  std::vector<unsigned> a;
  std::cin >> n;
  for(unsigned i = 0; i < n; i++){
    std::cin >> buf;
    a.push_back(buf);
  }

  shell_sort(a.data(),a.size());
  for(auto &v : a){
    std::cout << v << '\n';
  }
}